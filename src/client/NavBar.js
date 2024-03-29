import * as React from 'react';
import PropTypes from 'prop-types';
import AppBar from '@mui/material/AppBar';
import Box from '@mui/material/Box';
import Divider from '@mui/material/Divider';
import Drawer from '@mui/material/Drawer';
import IconButton from '@mui/material/IconButton';
import List from '@mui/material/List';
import ListItem from '@mui/material/ListItem';
import ListItemIcon from '@mui/material/ListItemIcon';
import ListItemText from '@mui/material/ListItemText';
import MenuIcon from '@mui/icons-material/Menu';
import Toolbar from '@mui/material/Toolbar';
import Typography from '@mui/material/Typography';
import Button from '@mui/material/Button';
import { Link, Outlet } from 'react-router-dom';
import './styles/NavBar.css';
import HomeIcon from '@mui/icons-material/Home';
import ArticleIcon from '@mui/icons-material/Article';

const drawerWidth = 240;
const navItems = ['Home', 'Docs'];

function NavBar(props) {
  const { window } = props;
  const [mobileOpen, setMobileOpen] = React.useState(false);

  const handleDrawerToggle = () => {
    setMobileOpen(!mobileOpen);
  };

  const drawer = (
    <Box onClick={handleDrawerToggle} sx={{ textAlign: 'center' }}>
      <Typography variant="h4" sx={{ my: 2, fontFamily: 'Nabla' }}>
        SunLang
      </Typography>
      <Divider />
      <List>
        {navItems.map((item) => (
          <ListItem key={item} button component={Link} to={`/${item}`}>
            <ListItemIcon>
              {item.toLowerCase().includes('home') ? (
                <HomeIcon />
              ) : (
                <ArticleIcon />
              )}
            </ListItemIcon>
            <ListItemText primary={item} />
          </ListItem>
          // <ListItem key={item} disablePadding sx={{ textAlign: 'center' }}>
          //   <ListItemIcon></ListItemIcon>
          //   <ListItemText primary={item} />
          // </ListItem>

          // <ListItem key={item} disablePadding>
          //   <ListItemButton sx={{ textAlign: 'center' }}>
          //     <Link to={`/${item.replace(' ', '-')}`}>
          //       <ListItemText primary={item}></ListItemText>
          //     </Link>
          //   </ListItemButton>
          // </ListItem>
        ))}
      </List>
    </Box>
  );

  const container =
    window !== undefined ? () => window().document.body : undefined;

  return (
    <Box sx={{ display: 'flex', height: '64px' }}>
      <AppBar
        component="nav"
        variant="contained"
        sx={{
          fontFamily: 'Nabla',
          background: 'rgb(255,242,17)',
          background:
            'radial-gradient(circle, rgba(255,242,17,1) 10%, rgba(255,203,0,1) 17%, rgba(255,127,0,1) 41%, rgba(255,100,0,1) 86%)',
          color: 'white',
        }}
      >
        <Toolbar>
          <IconButton
            color="inherit"
            aria-label="open drawer"
            edge="start"
            onClick={handleDrawerToggle}
            sx={{ mr: 2, display: { sm: 'none' } }}
          >
            <MenuIcon />
          </IconButton>
          <Typography
            variant="h4"
            component="div"
            sx={{
              fontFamily: 'Nabla',
              flexGrow: 1,
              display: { xs: 'none', sm: 'block' },
              textAlign: 'start',
            }}
          >
            SunLang
          </Typography>

          <Box sx={{ display: { xs: 'none', sm: 'block' } }}>
            {navItems.map((item) => (
              <Button key={item} sx={{ color: '#fff' }}>
                <Link
                  style={{
                    fontFamily: 'Reem Kufi Fun',
                    color: 'inherit',
                    textDecoration: 'none',
                  }}
                  to={`/${item.replace(' ', '-')}`}
                >
                  {item}
                </Link>
              </Button>
            ))}
          </Box>
        </Toolbar>
      </AppBar>
      <Box component="nav">
        <Drawer
          container={container}
          variant="temporary"
          open={mobileOpen}
          onClose={handleDrawerToggle}
          ModalProps={{
            keepMounted: true, // Better open performance on mobile.
          }}
          sx={{
            display: { xs: 'block', sm: 'none' },
            '& .MuiDrawer-paper': {
              boxSizing: 'border-box',
              width: drawerWidth,
            },
          }}
        >
          {drawer}
        </Drawer>
      </Box>
      <Box component="main" sx={{ p: 3 }}>
        <Toolbar />
      </Box>
    </Box>
  );
}

export default NavBar;
